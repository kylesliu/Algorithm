package main

import (
	"fmt"
	"math/rand"
	"time"
)

func BubbleSort(array []int) {
	swapCount := 1
	for swapCount > 0 {
		swapCount = 0
		for itemIndex := 0; itemIndex < len(array)-1; itemIndex++ {
			if array[itemIndex] > array[itemIndex+1] {
				array[itemIndex], array[itemIndex+1] = array[itemIndex+1], array[itemIndex]
				swapCount += 1
			}
		}
	}
}

func main() {
	// 生成随机长度的的数组
	random := rand.New(rand.NewSource(time.Now().UnixNano()))
	array := make([]int, 10000)

	for i := range array {
		array[i] = random.Intn(100)
	}

	start := time.Now()
	BubbleSort(array)
	rangeTime := time.Since(start)
	fmt.Println("Array Length: ", len(array))
	fmt.Println("Run Time:     ", rangeTime)
}
