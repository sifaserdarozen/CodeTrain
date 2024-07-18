package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
    "unicode"
)

/*
 * Complete the 'superDigit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
 *  2. INTEGER k
 */

func calcSum ( n string) int64 {
    sum := int64(0)
    for _, ch := range n {
        if  unicode.IsDigit(ch) {
            sum += int64(ch - '0')
        }
    }
    return sum
}

func superDigit(n string, k int32) int32 {
    // Write your code here
    num := calcSum(n) * int64(k)
    for num >= 10 {
        newNum := int64(0)
        for num > 0 {
            newNum += num % 10
            num /= 10
        }
        num = newNum
    }
    return int32(num)
}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 16 * 1024 * 1024)

    stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
    checkError(err)

    defer stdout.Close()

    writer := bufio.NewWriterSize(stdout, 16 * 1024 * 1024)

    firstMultipleInput := strings.Split(strings.TrimSpace(readLine(reader)), " ")

    n := firstMultipleInput[0]

    kTemp, err := strconv.ParseInt(firstMultipleInput[1], 10, 64)
    checkError(err)
    k := int32(kTemp)

    result := superDigit(n, k)

    fmt.Fprintf(writer, "%d\n", result)

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
