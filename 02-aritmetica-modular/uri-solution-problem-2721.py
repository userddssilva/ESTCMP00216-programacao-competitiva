reindeers = ['', 'Dasher', 'Dancer', 'Prancer', 'Vixen', 'Comet', 'Cupid','Donner', 'Blitzen' ,'Rudolph']
snow_balls = input().split(' ')

sum = 0
for sbs in snow_balls:
    sum += int(sbs)

index = sum % 9
if index == 0:
    index = 9