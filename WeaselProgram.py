import random
import string

def gerandoCaracteres (): # Escolhe um caractere ascii ABCDEFGHIJKLMNOPQRSTUVWXYZ
  return random.choice(string.ascii_uppercase + ' ')


def gerandoStrings (tamanho): # tamanho da frase original
  caracteres = list()
  for i in range(tamanho):
    caracteres.append(gerandoCaracteres())
  return ''.join(caracteres) # retorna a string da lista de caracteres

 
def comparandoStrings (string, fraseOriginal):
  soma = 0
  for i in range(len(string)):
    soma += int(string[i] == fraseOriginal[i])
  return soma # retorna a soma dos caracteres que são iguais em posicao


def AlterandoString (string):
  string = list(string) # converte string para lista
  for i in range(len(string)):
    if random.randint(1, 100) <= 5: # se bater 5% (probabilidade)
      string[i] = gerandoCaracteres() # gera outro caractere na posicao que bateu

  return ''.join(string) # retorna a lista em formato de string


def main (fraseOriginal):
  geracao = 1
  achou = False 
  string_aleatoria = gerandoStrings(len(fraseOriginal)) # gera a string com o tamanho da frase

  while not achou: # ate saber se a string foi achada
    lista_strings = list()
    lista_scores = list()
    score_maximo = (0, 0) # guarda a posicao e o score

    for i in range(100): 
      # fazer 100 copias da string alterada e guardar na lista lista_strings
      lista_strings.append(AlterandoString(string_aleatoria)) 
      # cada posicao da lista_strings é uma copia da string modificada e ela eh comparada com a frase original
      lista_scores.append(comparandoStrings(lista_strings[i], fraseOriginal)) 
      
      if lista_scores[i] > score_maximo[1]:
        score_maximo = (i, lista_scores[i])

    achou = score_maximo[1] == len(fraseOriginal)
    string_aleatoria = lista_strings[score_maximo[0]] # a nova string eh a que teve a maior pontuacao

    print("Geracao: {} \nFrase: {} \nPontuacao: {} \n\n".format(geracao, string_aleatoria, score_maximo[1]))
    geracao += 1


frase = 'METHINKS IT IS LIKE A WEASEL'
main(frase)