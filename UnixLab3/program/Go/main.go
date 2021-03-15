package main

import (
    "fmt"
    "os"
    "strconv"
)

func Sum(first, second float64) float64 {
    return first + second
}

func main() {
    if (len(os.Args) < 3) {
        fmt.Println("Not enough args to complete the program!")
        return
    }

    first, error1  := strconv.ParseFloat(os.Args[1], 64)
    second, error2 := strconv.ParseFloat(os.Args[2], 64)

    if (error1 != nil || error2 != nil) {
        fmt.Println("Parse error...")
        os.Exit(1)
    }

    fmt.Printf("%v + %v = %v\n", first, second, Sum(first, second))
}
