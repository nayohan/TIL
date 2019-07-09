import numpy as np
import matplotlib.pyplot as plt

def to_categori(y):
    #(42000,)
    y_len = y.shape
    y_len = (int(str(y_len[0])))

    result = np.zeros((y_len,10))
    for i in range (0,y_len):
        for j in range(0,10):
            if(y[i] == j):
                result[i,j]=1;
    return result

def to_value(y):
    #(28000,10)
    y_len = y.shape
    y_len = (int(str(y_len[0])))
    
    result_y = np.zeros((y_len))
    
    for i in range(0,28000):
        max_y = 0
        for j in range(0,10):
            if(max_y < y[i,j]):
                max_y = y[i,j]
                result_y[i]=j
    return result_y

def show_data(x, y):
    digit = np.reshape(x, (28,28))
    plt.imshow(digit, cmap=plt.cm.binary)
    plt.show()
    print(y)
    