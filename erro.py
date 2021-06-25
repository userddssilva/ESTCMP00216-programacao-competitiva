2021-06-24 16:24:57 [NBOA1J0166] INFO: Handling configuration wifi_ssid
2021-06-24 16:24:58 [NBOA1J0166] INFO: max_steps: 1
2021-06-24 16:24:58 [NBOA1J0166] INFO: Handling window com.google.android.setupwizard/com.google.android.setupwizard.predeferred.connecttowifiactivity
2021-06-24 16:25:14 [NBOA1J0166] ERROR: Failed to scroll to any of chlorian skip buttons.
2021-06-24 16:25:17 [NBOA1J0166] INFO: Skipped Button 'Next' in screen position: (540.5, 1494.5)
2021-06-24 16:25:18 [NBOA1J0166] INFO: Handling configuration wifi_ssid
2021-06-24 16:25:19 [NBOA1J0166] INFO: Handling configuration wifi_ssid
2021-06-24 16:25:20 [NBOA1J0166] INFO: Handling configuration wifi_ssid
2021-06-24 16:25:21 [NBOA1J0166] INFO: Handling configuration wifi_ssid
2021-06-24 16:25:21 [NBOA1J0166] INFO: Handling configuration wifi_ssid
2021-06-24 16:25:22 [NBOA1J0166] INFO: Handling configuration wifi_ssid
2021-06-24 16:25:26 [NBOA1J0166] ERROR: Check the screendump files at ./ERROR_NBOA1J0166.png / ./ERROR_NBOA1J0166.uix
2021-06-24 16:25:26 [NBOA1J0166] INFO: Re-enabling NFC...
2021-06-24 16:25:27 [NBOA1J0166] INFO: Disabling stay awake...
FAILED
tests/mca_1168847.py:61 (mca_1168847_setup[True])
main_device = <chlorian.connection.Connection object at 0x7f41ec25ffd0>
logger = <test_case_logger.TestCaseLoggerPlugin object at 0x7f41ec4440a0>

    @skywalker.validation(f'{DALEK_ID}.setup')
    @skywalker.description(f'[{DALEK_ID}] Setup')
    @skywalker.tags('factory_reset')
    def mca_1168847_setup(main_device, logger):
        logger.log('Performing FDR on DUT', step=1, emphasis_header='INITIAL SETUP')
        main_device.moto_settings.system.confirm_reset.clear_everything()
        main_device.input.wake_up()
        quick_settings.set_stay_awake(main_device, True)
        main_device.setup_wizard.main.wait_controller(REACHED_SETUP_WIZARD_TIMEOUT)
        logger.log('Configuring default setup wizard screens until it gets to add account controller',
                   emphasis_header='INITIAL SETUP')
>       SetupWizardSkip(main_device, target_window=main_device.setup_wizard.setup_gms_account.window).skip_setup(
            wifi_ssid=main_device.settings.WIFI_SSID,
            wifi_password=main_device.settings.WIFI_PASSWORD,
        )

tests/mca_1168847.py:73: 
_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 

self = <setupwizard_skip.__main__.SetupWizardSkip object at 0x7f4256577eb0>
wifi_ssid = 'Gibson_Fibra_5G', wifi_password = '23571323', wifi_identity = None
google_account = None, google_password = None, use_mobile_data = False
pin = None, save_controllers_name = False, no_location = False
frp_lockscreen = None, afw_account = None, dpc = None

    def skip_setup(self, wifi_ssid=None, wifi_password=None, wifi_identity=None, google_account=None,
                   google_password=None, use_mobile_data=False, pin=None, save_controllers_name=False, no_location=False,
                   frp_lockscreen=None, afw_account=None, dpc=None):
        skip_button_deque = deque(maxlen=7)
    
        def __get_vision_widgets():
            # give priority for text widget specs and if none is found, try with image templates
            for widget_description, text_widget_props in FORCE_VISION_TEXT_TEMPLATES.items():
                try:
                    text_coords = force_vision.get_text_coordinates(device=self.a, **text_widget_props)
                    for text_coord in text_coords:
                        yield widget_description, text_coord
                except Exception as error:
                    self.logger.error('Failed to get text coordinates.\nExceptions:{}'.format(error))
    
            for widget_description, image_widget_props in FORCE_VISION_IMAGE_TEMPLATES.items():
                try:
                    w = force_vision.get_image_position(device=self.a, **image_widget_props)
                    if w:
                        yield widget_description, tuple(reversed(w))
                except Exception as error:
                    self.logger.error('Failed to get image position.\nException:{}'.format(error))
    
        def __check_infinite_loop_protection():
            if len(skip_button_deque) == 3 and len(set(skip_button_deque)) <= 2:
                self.__call_waitfor_hooks()
            elif len(skip_button_deque) == 5 and len(set(skip_button_deque)) <= 2:
                dump_files = util.take_screenshot(self.a)
                self.logger.error('Possible Infinite loop detected: Too many attempts at the same SKIP '
                                  'button in the same window: {}'.format(set(skip_button_deque)))
                self.logger.error('Check the screendump files at {} / {}'.format(dump_files['png'], dump_files['uix']))
                raise InfiniteLoopException('Possible Infinite loop detected. Halting execution.')
    
        def __config():
            try:
                if use_mobile_data and 'use_mobile_data' not in self.__cache_config_done:
                    self.logger.info("Handling configuration use_mobile_data")
                    if self.a.force.current_controller_name == 'setup_wizard.setup_network':
                        self.a.setup_wizard.setup_network.use_cel_data()
                        self.__cache_config_done.append('use_mobile_data')
    
                if (wifi_ssid or wifi_password) and 'wifi_ssid' not in self.__cache_config_done:
                    self.logger.info("Handling configuration wifi_ssid")
                    if self.a.force.current_controller_name == 'setup_wizard.setup_network':
                        self.a.setup_wizard.setup_network.connect_wifi(wifi_ssid, wifi_password, wifi_identity)
                        self.__cache_config_done.append('wifi_ssid')
    
                if google_account and google_password and 'google_account' not in self.__cache_config_done:
                    self.logger.info("Handling configuration google_account")
                    if self.a.force.current_controller_name == 'google_account.email_phone':
                        w = self.a.ui.screen().widget(text=re.compile('^GO BACK$', re.IGNORECASE))
                        if w:
                            w.tap()
                            time.sleep(1)
                        self.a.google_account.email_phone.insert_email_phone(google_account)
                        self.a.google_account.password.insert_password(google_password)
                    if self.a.force.current_controller_name == 'setup_wizard.setup_gms_account':
                        self.a.setup_wizard.setup_gms_account.add_account(google_account, google_password)
                        if self.a.force.current_controller_name == 'setup_wizard.setup_previous_confirm_account':
                            self.a.setup_wizard.setup_previous_confirm_account.confirm_previous_account()
    
                    if self.a.force.current_controller_name == 'setup_wizard.setup_confirm_account':
                        self.a.setup_wizard.setup_confirm_account.confirm_account()
                        self.__cache_config_done.append('google_account')
    
                if afw_account and dpc and 'afw_account' not in self.__cache_config_done:
                    self.logger.info("Handling configuration afw_account")
                    if self.a.force.current_controller_name == 'setup_wizard.setup_gms_account':
                        w = self.a.ui.screen().widget(text=re.compile('^GO BACK$', re.IGNORECASE))
                        if w:
                            w.tap()
                            time.sleep(1)
                    if self.a.force.current_controller_name == 'google_account.email_phone':
                        self.a.google_account.email_phone.insert_email_phone(afw_account)
                        self.__cache_config_done.append('afw_account')
    
                if dpc and 'dpc' not in self.__cache_config_done:
                    self.logger.info("Handling configuration with DPC")
                    if self.a.force.current_controller_name == 'google_account.enterprise_mobility_management':
                        if dpc == 'owner':
                            self.logger.info("Handling configuration DPC Owner")
                            self.a.google_account.owner_account.setup_management.select_device_owner()
                        else:
                            self.logger.info("Handling configuration DPC Managed")
                            self.a.google_account.owner_account.setup_management.select_managed_profile()
                        self.a.google_account.owner_account.setup_management.next()
                        self.__cache_config_done.append('dpc')
    
                if self.enter_demo_mode and 'demo_mode.retail_mode' not in self.__cache_config_done:
                    self.logger.info("Handling configuration demo retail mode")
                    if self.a.force.current_controller_name == 'demo_mode.retail_mode':
                        self.__cache_config_done.append('demo_mode.retail_mode')
                        self.a.demo_mode.retail_mode.exit_screen()
            except Exception as e:
                self.logger.error("Could not finish configuration gracefully: {}".format(str(e)))
    
        def __finished():
            result = False
            for _ in range(3):
                __config()
                win = self.a.ui.window()
                if win and win != 'null':
                    result = self.target_window in str(win).lower()
                    if result:  # quick double check!
                        win = str(self.a.ui.window()).lower()
                        self.logger.info("Quick double check window {}".format(win))
                        result = self.target_window in win
                        break
                time.sleep(.5)
            return result
    
        def __deactivate_switches(s):
            try:
                sw = s.widget(**SWITCH_WIDGETS)
                if sw and sw.is_checked():
                    self.logger.info(
                        "Deactivating option: id[{}] text[{}] contentDesc[{}]".format(sw.id().encode('utf-8'),
                                                                                      sw.text().encode('utf-8'),
                                                                                      sw.content_desc().encode(
                                                                                          'utf-8')))
                    sw.tap()
            except:
                pass
    
        def __unclip_button(w):
            if not isinstance(self.a, chlorian.connection.Connection):  # only available for Chlorian connection
                return w
    
            if w and w.y() + w.height() > self.a.ui.screen().screen_height:  # clipped at the bottom
                self.a.input.scroll_down(top=self.a.device.height() * .7)
                time.sleep(.7)  # give it time for animation
                # all of the SKIP_WIDGETS are mapped with text, add type for safety
                return self.a.ui.screen().widget(text=w.text(), type=w.type())
            return w
    
        def __try_skip_buttons(s):
            buttons = s.widgets(**SKIP_WIDGETS)
            if not buttons:
                try:
                    try:
                        buttons = self.a.ui.waitfor_ex(**SKIP_WIDGETS)
                    except:
                        if self.__call_waitfor_hooks():
                            buttons = self.a.ui.waitfor_ex(**SKIP_WIDGETS)
                        else:
                            try:
                                buttons = [self.a.ui.scrollto(max_pages=4, scroll_direction='down', **SKIP_WIDGETS)]
                            except:
                                self.logger.error("Failed to scroll to any of chlorian skip buttons.")
                except:
                    pass
            #  remove boundless widgets
            filtered_buttons = itertools.chain((w for w in buttons if w.center() != (0, 0)), __get_vision_widgets())
            for btn in filtered_buttons:
                if isinstance(btn, tuple):
                    widget_description, position = btn
                    message = 'Skipped {} in screen position: {}'.format(widget_description, position)
                    self.logger.info(message)
                    self.a.input.tap(*position)
                    skip_button_deque.append("{}:{}".format(win, message))
                    return True
                else:
                    btn = __unclip_button(btn)
                    if btn and btn.is_enabled() and 'WebView' not in btn.type():
                        self.logger.info(
                            "Skipped with button: id[{}] text[{}] contentDesc[{}]".format(btn.id().encode('utf-8'),
                                                                                          btn.text().encode('utf-8'),
                                                                                          btn.content_desc().encode(
                                                                                              'utf-8')))
                        btn.tap()
                        skip_button_deque.append("{}:{}".format(win, str(btn).encode('utf-8')))
                        time.sleep(.7)
                        return True
            return False
    
        def __wait_loading_widgets():
            try:
                self.logger.info("Waiting for loading widgets ...")
                self.a.ui.waitfor(timeout=30, **LOADING_WIDGETS)
                self.logger.info("Loading done!")
            except:
                self.logger.warning("Loading widgets are taking too long to finish!")
    
        @contextmanager
        def __setup_wizard_setup():
            try:
                # Disable NFC: other devices close by are interfering with the Setup during the 'Tap & Go' configuration
                self.logger.info("Disabling NFC...")
                util.set_nfc_status(self.a, False)
                self.logger.info("Enabling stay awake...")
                quick_settings.set_stay_awake(self.a, True)  # Avoid to turn the screen off during the execution
                yield
            finally:
                # Enable NFC back on
                self.logger.info("Re-enabling NFC...")
                util.set_nfc_status(self.a, True)
                self.logger.info("Disabling stay awake...")
                quick_settings.set_stay_awake(self.a, False)
    
        if save_controllers_name:
            controllers_name = []
    
        with __setup_wizard_setup():
            # unlock device
            self.a.ui.unlock(pin=pin)
            self.a.input.home()  # just in case the device is not in the SetupWizard screen
            if self.a.ui.screen().widget(text='Wrong PIN'):
                raise CannotUnlockDeviceException("Device is locked with a PIN. {}"
                                                  .format('Wrong PIN: {}'.format(pin) if pin else 'No PIN informed. Cannot unlock.'))
    
            self.check_language()
            if self.enter_demo_mode:
                self.enable_demo_mode()
            max_steps = 30
    
            while not __finished() and max_steps > 0:
                if self.fast_skip:
                    self._four_steps_skip()
    
                if save_controllers_name:
                    try:
                        controllers_name.append(self.a.force.current_controller_name)
                    except Exception as e:
                        self.logger.info('Exception trying get current controller name'.format(e))
    
                self.logger.info("max_steps: {}".format(max_steps))
                max_steps -= 1
                win = str(self.a.ui.window()).lower()
                self.logger.info("Handling window {}".format(win))
    
                if 'aod' in win or 'turnedoff' in win:
                    self.logger.info("Unlocking device...")
                    self.a.ui.unlock()
                    time.sleep(.5)
                    continue
    
                elif 'statusbar' in win:
                    self.a.input.back(3)
                    self.a.input.home()
                    time.sleep(.5)
                    continue
    
                elif 'cellbroadcastsettings' in win:
                    self.logger.info("skip cellbroadcastsettings...")
                    self.a.input.back()
                    time.sleep(.5)
                    continue
    
                elif 'emergencydialer' in win:
                    self.a.input.back()
                    time.sleep(.5)
                    continue
    
                elif re.compile(r'(wifisettingsforprcsetupwizard|wifisettingsforsetupwizardtest)').findall(win):
                    if wifi_ssid is None:
                        if self.a.ui.screen().widget(text="Please insert sim card"):
                            self.logger.info('SIM1 card is not found! Please check SIM1 card status')
                            continue
                        time.sleep(10) # wait for the wifi list to appear so we can reliably target the correct position of the SIM card name on screen
                        self.a.ui.waitfor(timeout=2, id="sim_card1").tap()
                        self.logger.info('SIM card Activation is going on, please wait a moment!')
                        try:
                            self.a.ui.waitfor(timeout=30, regexp='(?i)Data sync')
                        except Exception as e:
                            self.logger.info('SIM card Activation failed! {}'.format(e))
                            bt_retry = self.a.ui.screen().widget(text='Retry')
                            if bt_retry:
                                self.logger.info('Retry again')
                                bt_retry.tap()
                                time.sleep(15)
                    else:
                        self.a.ui.waitfor(timeout=20, text=wifi_ssid).tap()
                        time.sleep(.5)
                        self.a.input.text(wifi_password)
                        self.a.ui.screen().widget(text='Connect').tap()
                        self.a.ui.waitfor(timeout=20, text="Skip").tap()
                    continue
    
                elif 'dfpoints' in win:
                    self.a.input.back()
                    time.sleep(.5)
                    continue
    
                elif 'simsetupactivity' in win:
                    if 'Mobile data preference' in self.a.ui.screen().texts() \
                            or 'SMS preference' in self.a.ui.screen().texts():
                        self.logger.info("Choosing a default SIM card...")
                        btn = self.a.ui.screen().widget(id='sud_items_summary').parent.parent
                        btn.tap()
    
                    elif 'Calls preference' in self.a.ui.screen().texts():
                        self.logger.info("Choosing a default SIM card for calls...")
                        btn = self.a.ui.screen().widget(text='Ask every time')
                        btn.tap()
    
                elif self.a.ui.is_input_method_up():
                    self.a.input.back()
                    time.sleep(.5)
                    continue
    
                elif 'mobilenetworkactivity' in win:
                    try:
                        bt_turn_on = self.a.ui.screen().widget(text='Turn on')
                        if bt_turn_on:
                            bt_turn_on.tap()
                    finally:
                        self.a.input.back()
                    continue
    
                elif re.compile(r'(googleservicesactivity|motolocationaccessactivity)').findall(win):
                    if no_location:
                        self._disable_location()
    
                elif re.compile(r'(motocrmretailoptin)').findall(win) and \
                        self.a.ui.screen().widget(type='android.widget.Switch'):
                    self._disable_email()
    
                elif self.a.moto_settings.security.confirm_lock_key.is_in_screen():
                    if frp_lockscreen:
                        self.a.moto_settings.security.confirm_lock_key.enter_lock(frp_lockscreen,
                                                                                  isinstance(frp_lockscreen, list))
                    else:
                        self.a.moto_settings.security.confirm_lock_key.exit_screen()
    
                elif self.a.setup_wizard.verify_pin.is_in_screen():
                    if frp_lockscreen:
                        self.a.setup_wizard.verify_pin.confirm_previous_lockscreen(frp_lockscreen)
    
                elif 'gestureonboardingsetactivity' in win:
                    self.logger.info("skip gestureonboardingsetacitivity...")
                    self.a.input.back()
                    time.sleep(.5)
                    continue
    
                elif 'QrScannerActivity' in win:
                    self.logger.info("skip Network QR code sync...")
                    self.a.ui.screen().widget(text='Need help?').tap()
                    time.sleep(.5)
                    continue
    
                s = self.a.ui.screen()
                __deactivate_switches(s)
                if not __try_skip_buttons(s):
                    __wait_loading_widgets()
                __check_infinite_loop_protection()
    
            if max_steps <= 0 and not __finished():
                dump_files = util.take_screenshot(self.a)
                self.logger.error('Check the screendump files at {} / {}'.format(dump_files['png'], dump_files['uix']))
>               raise RuntimeError('Max steps timed out')
E               RuntimeError: Max steps timed out

../../automation-contrib/pypi_packages/setupwizard_skip/setupwizard_skip/__main__.py:611: RuntimeError