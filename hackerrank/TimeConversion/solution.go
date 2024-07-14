// Compute Complexity O(N)
// space Complexity 
package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strings"
)

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

func timeConversion(s string) string {
    // Write your code here
    
    // get the individual parts
    var hour int
    var min string
    var sec string
    _, err := fmt.Sscanf(s, "%2d:%2s:%2s", &hour, &min, &sec)
    if err != nil {
        return s
    }

    if militaryTime, _, found := strings.Cut(s, "AM"); found {
        if hour == 12 {
             return fmt.Sprintf("%02d:%s:%s", 0, min, sec)
        } 
        return militaryTime
    } else if militaryTime, _, found := strings.Cut(s, "PM"); found {
       if hour == 12 {
            return militaryTime
        }

        return fmt.Sprintf("%02d:%s:%s", hour + 12, min, sec)
        
    } else {
        return s
    }
}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 16 * 1024 * 1024)

    stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
    checkError(err)

    defer stdout.Close()

    writer := bufio.NewWriterSize(stdout, 16 * 1024 * 1024)

    s := readLine(reader)

    result := timeConversion(s)

    fmt.Fprintf(writer, "%s\n", result)

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
