# brief annotation of a roulette wheel algorithm written using numpy at the AI4R class
import numpy as np

p3 = [] # our resampled array

w = np.array(w) # array of weights previously computed, using a weight function or fitness function for GA's
wn = w/np.sum(w) #normalize the weight so that the sum of all weights equals 1
suma = np.cumsum(wn) #perform a scan operation, that is, sum all preceding values of array at index i
for i in range(N):
    r = random.uniform(0,1)
    idx = np.searchsorted(s, r) # search would-be insertion spot for a sorted array - this will give us our individual to resample.
    p3.append(p[idx]) # add that individual to our new array