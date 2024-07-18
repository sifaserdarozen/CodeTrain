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
 * Complete the 'balancedSums' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

// Compute Complexity O(N)
// Space Complexity O(N)
// Calculate refix & postfix sum
// find idx of where prefix == postfix
// 1 2 3 4 3 2 1
// 1  3  6  10 13 15 16
// 16 15 13 10 6  3  1
func balancedSums(arr []int32) string {
    // Write your code here
    N := len(arr)
    
    // calculate prefix and postfix arrays
    prefix := make([]int32, N)
    postfix := make([]int32, N)
    prefixSum := int32(0);
    postfixSum := int32(0);
    for i := 0; i < N; i++ {
        prefixSum += arr[i]
        prefix[i] = prefixSum
        postfixSum += arr[N - i - 1]
        postfix[N - i - 1] = postfixSum
    }
    
    for i := 0; i < N; i++ {
        if prefix[i] == postfix[i] {
            return "YES"
        }
    }
    
    return "NO"
}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 16 * 1024 * 1024)

    stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
    checkError(err)

    defer stdout.Close()

    writer := bufio.NewWriterSize(stdout, 16 * 1024 * 1024)

    TTemp, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
    checkError(err)
    T := int32(TTemp)

    for TItr := 0; TItr < int(T); TItr++ {
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

        result := balancedSums(arr)

        fmt.Fprintf(writer, "%s\n", result)
    }

    writer.Flush()
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
