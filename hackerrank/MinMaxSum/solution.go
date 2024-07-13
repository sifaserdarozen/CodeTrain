// Compute Complexity O(N)
// Space Complexity O(1)

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
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

func miniMaxSum(arr []int32) {
    // Write your code here
    
    // initialize min, max and total values
    min := arr[0]
    max := arr[0]
    total := int64(0)
    
    // iterate over the container to calculate sum and update
    // min and max values
    for _, v := range arr {
        if v < min {
            min = v
        }
        if v > max {
            max = v
        }
        total += int64(v)
    }

    minSum := total - int64(max)
    maxSum := total - int64(min)
    
    fmt.Println(minSum, maxSum)
}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 16 * 1024 * 1024)

    arrTemp := strings.Split(strings.TrimSpace(readLine(reader)), " ")

    var arr []int32

    for i := 0; i < 5; i++ {
        arrItemTemp, err := strconv.ParseInt(arrTemp[i], 10, 64)
        checkError(err)
        arrItem := int32(arrItemTemp)
        arr = append(arr, arrItem)
    }

    miniMaxSum(arr)
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
