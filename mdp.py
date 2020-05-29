s1 = 0
s2 = 10
s3 = 15
s4 = 12
s5 = 15
s6 = 10
s7 = 12

for i in range(2):
    s1 = s2 * 0.8 + s3 * 0.2
    #s1 = (s2 * 0.6) + (s3 * 0.4)
    #s1c = s2 * 0.1 + s3 * 0.9

    s2 = 10 + (0.9 * s4)
    
    s3 = 15 + (0.3 * s6)
    
    s4 = 12 + (0.4 * s5)
    
    s6 = 10 + (0.7 * s7)
    
    print("iteration", i)
    print("s1", s1)
    print("s2", s2)
    print("s3", s3)
    print("s4", s4)
    print("s6", s6)

print("simuklating one more step, comparing other policies:")    
s1a = (s2 * 0.8) + (s3 * 0.2)
s1b = (s2 * 0.6) + (s3 * 0.4)
s1c = (s2 * 0.1) + (s3 * 0.9)

s2c = 10 + (0.6 * s4)
s2b = 10 + (0.9 * s4)

s3a = 15 + (0.3 * s6)
s3b = 15 + (0.1 * s6)

s4 = 12 + (0.4 * s5)

s6 = 10 + (0.7 * s7)

print("s1a", s1a)
print("s1b", s1b)
print("s1c", s1c)
print("s2c", s2c)
print("s2b", s2b)
print("s3a", s3a)
print("s3b", s3b)