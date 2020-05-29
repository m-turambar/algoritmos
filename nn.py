import numpy as np
import math

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

X = np.matrix([[7.],[2.]])
Y = np.matrix([[8.],[3.]])

W0 = np.matrix([[0.11, 0.73, 0.72],[0.09, 0.75, 0.79]])
W1 = np.matrix([[0.80, 0.38],[0.72, 0.66],[0.23, 0.87]])
a = W0.T*X

print(a)
h = sigmoid(a)
#h = np.vectorize(sigmoid)(a)
print(h)

y = W1.T*h
print("salida y: ", y)

dE = -(Y - y)
print("derivadas:", dE)

#temporal, video youtube
dk = np.multiply(np.multiply(y,(1-y)),(y - Y))

print("W1", W1)
#print("dk:", dk)

lol = dk.T

w1 = np.multiply(W1[0], lol)
print("dEw1", w1)
w2 = np.multiply(W1[1], lol)
print("dEw2", w2)
w3 = np.multiply(W1[2], lol)
print("dEw3", w3)

print(w1.shape)

wd = np.arange(6).reshape(3,2)
wd[0][0] = w1[0]
wd[0][1] = w1[1]
wd[1][0] = w2[0]
wd[1][1] = w2[1]
wd[2][0] = w3[0]
wd[2][1] = w3[1]

print("wd", wd)

alfa = 0.3
wp = W1 - alfa*wd

print("nuevos w:", wp)