import numpy as np

def CalculatePearson(x, y):
    mean_of_x = np.mean(x)
    mean_of_y = np.mean(y)
    x_n = x - mean_of_x
    y_n = y - mean_of_y
    
    return  np.mean(x_n * y_n)/(np.std(x) * np.std(y))
    

def test():
    x = [15,  12,  8,   8,   7,   7,   7,   6,   5,   3]
    y = [10,  25,  17,  11,  13,  17,  20,  13,  9,   15]
    value = CalculatePearson(x, y)
    print("%.3f" %value)
    
def main():
    test()
  
if __name__ == "__main__":
    main()
