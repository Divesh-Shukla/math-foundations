import math

def vec_add(a,b):
    result = []
    if len(a)!=len(b):
        print("Invalid operation!\n")
        return None

    for i in range(len(a)):
        result.append(a[i]+b[i])

    return result

def vec_scale(a, scalar):
    scaledVec = []
    for i in range(len(a)):
        scaledVec.append(scalar*a[i])
    return scaledVec

def vec_dot(a,b):
    if len(a)!=len(b):
        print("Invalid Operation!\n")
        return None
    dotProduct = 0
    for i in range(len(a)):
        dotProduct += a[i]*b[i]
    
    return dotProduct

def vec_magnitude(a):
    if len(a)==0:
        return None
    sum = 0
    for i in range(len(a)):
        sum += a[i]**2
    return sum**0.5

def vec_normalized(a):
    mag = vec_magnitude(a)
    normalizedVector = []
    for i in range(len(a)):
        normalizedVector.append(a[i]/mag)
    return normalizedVector

def vec_angle(a,b):
    if len(a)!=len(b):
        return None
    magA = vec_magnitude(a)
    magB = vec_magnitude(b)
    cosTheta = vec_dot(a,b)/(magA*magB) 
    theta = math.acos(cosTheta)
    return theta

def vec_projection(a,b):
    if len(a)!=len(b):
        return None
    projection = []
    magB = vec_magnitude(b)
    dotP = vec_dot(a,b)
    scalar = dotP/(magB**2)
    for l in range(len(a)):
        projection.append(b[l]*scalar)
    return projection

a = [3, 0]
b = [0, 4]
print(vec_magnitude(vec_add(a, b)))  # should print 5.0
   
a = [1, 0]
b = [0, 1]
print(vec_angle(a, b))  # should print 1.5707... which is pi/2, a right angle

a = [3, 4]
b = [1, 0]
print(vec_projection(a, b))  # should print [3.0, 0.0]
