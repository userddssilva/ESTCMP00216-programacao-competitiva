j,r = input().split(' ')
j,r = int(j), int(r)

pontos_rodadas = input().split(' ')
somas_pontos = [0] * j
maior = 0
vencedor = -1

for i in range(j*r):
    pontos = int(pontos_rodadas[i])
    somas_pontos[i%j] += pontos 

for i in range(len(somas_pontos)):
    if somas_pontos[i] >= maior:
        maior = somas_pontos[i]
        vencedor = i + 1

print(vencedor)