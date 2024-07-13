// Compute Complexity O(N)
// space Complexity O(1)

package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

func plusMinus(arr []int32) {
    // Write your code here
    
    // count the positive and negative occurances
    noOfPos := 0;
    noOfNeg := 0;
    for _, v := range arr {
        if v > 0 {
            noOfPos++;
        } else if v < 0 {
            noOfNeg++;
        }
    }
    
    // get the zeros from total
    total := len(arr)
    noOfZero := total - noOfPos - noOfNeg
    
    // get float64 ratios
    posRatio := float64(noOfPos) / float64(total)
    negRatio := float64(noOfNeg) / float64(total)
    zeroRatio := float64(noOfZero) / float64(total)
    
    // print to 6 decimal point
    fmt.Printf("%.6f\n", posRatio)
    fmt.Printf("%.6f\n", negRatio)
    fmt.Printf("%.6f\n", zeroRatio)
}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 16 * 1024 * 1024)

    nTemp, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
    checkError(err)
    n := int32(nTemp)

    arrTemp := strings.Split(strings.TrimSpace(readLine(reader)), " ")

    var arr []int32

    for i := 0; i < int(n); i++ {
        arrItemTemp, err := strconv.ParseInt(arrTemp[i], 10, 64)
        checkError(err)
        arrItem := int32(arrItemTemp)
        arr = append(arr, arrItem)
    }

    plusMinus(arr)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
    if err != nil {
        panic(err)
    }
}
