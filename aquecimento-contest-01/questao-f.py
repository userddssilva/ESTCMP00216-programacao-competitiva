text = input().split(' ')
new_text = ''
for word in text:
    if len(word) > 4:
        if word[:2] in word[2:]:
            word = word[2:]
    new_text += ' ' + word
print(new_text[1:])