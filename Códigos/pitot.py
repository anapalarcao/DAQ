#esse codigo sempre recebe a contagem zerada da pressao qnd extrapola 128. Isso significa que teremos que ajustar o range de acordo com o valor medido no pitot.
#Se rodar no Thonny ele printa e salva no txt em decimal na maior naice!
#Todavia se rodar no terminal ele NAO printa nem salva no txt o numero em decimal, apenas a parte inteira.PQ JESUS??

from smbus import SMBus
import time

bus = SMBus(1)
address = 0x04
number = 0

def writeNumber(value):
    bus.write_byte(address, value)# bus.write_byte_data(address, 0, value)
    return -1

def readNumber():
    number = bus.read_byte(address) # number = bus.read_byte_data(address, 1)
    return number



while True:
	
	GPIO.output(18,GPIO.HIGH)
	inteiro = readNumber()
	#time.sleep(1)		#sleep one second
	decimal = (inteiro+256)/100 #no dado enviado eh multiplicado por 100, por isso temos de dividir e o 256 eh o "offset" pra ajustar o valor por causa dos 7bits
	#junto = inteiro + (decimal/100)
	print (inteiro)
	#time.sleep(1)		#sleep one second
	#print ('oi')
	print (decimal)
	#print ('teamo')
	#print (junto)
	#print ("Arduino: Hey RPI, I received a digit ", number)
	#var = 2
	#writeNumber(var)
	f = open ("/home/pi/Desktop/teste/pitot.txt",  'a')
	f.write(str(decimal))
	f.close
	time.sleep(0.5)
	GPIO.output(18,GPIO.LOW)