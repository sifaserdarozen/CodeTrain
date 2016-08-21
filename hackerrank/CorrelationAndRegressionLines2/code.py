import numpy as np

def test():
    x = [15,  12,  8,   8,   7,   7,   7,   6,   5,   3]
    y = [10,  25,  17,  11,  13,  17,  20,  13,  9,   15]
    
    poly = np.polyfit(x, y, 1)
    print("%.3f" %poly[0])
    
def main():
    test()
  
if __name__ == "__main__":
    main()

