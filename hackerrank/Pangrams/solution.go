// Compute Complexity O(N)
// Space Complexity O(1)

package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strings"
    "unicode"
)

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

func pangrams(s string) string {
    // Write your code here
    alphSize := 'z' - 'a' +1
    alph := make([]bool, alphSize)
    remaining := alphSize
    
    for _, ch := range s {
        if !unicode.IsLetter(ch) {
            continue
        }
        
        ch = unicode.ToLower(ch)
        if false == alph[ch - 'a'] {
            alph[ch - 'a'] = true
            remaining --;
            if 0 == remaining {
                return "pangram"
            }
        }
    }
    
    if 0 == remaining {
      return "pangram"
    }
    
    return "not pangram"
}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 16 * 1024 * 1024)

    stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
    checkError(err)

    defer stdout.Close()

    writer := bufio.NewWriterSize(stdout, 16 * 1024 * 1024)

    s := readLine(reader)

    result := pangrams(s)

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
