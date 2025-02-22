func max(piles []int) int {
	max := piles[0]
	for _, val := range piles {
		if val > max {
			max = val
		}
	}
	return max
}

func canKokoEatAll(eatRate int, piles []int, h int) bool {
	sum := 0
	for _, p := range piles {
		sum += p / eatRate
		if p%eatRate > 0 {
			sum += 1
		}
		if sum > h {
			return false
		}
	}

	return sum <= h
}

func binarySearch(start int, end int, piles []int, h int) int {
	if start >= end {
		return end
	}

	mid := (start + end) / 2

	if canKokoEatAll(mid, piles, h) {
		return binarySearch(start, mid, piles, h)
	} else {
		return binarySearch(mid+1, end, piles, h)
	}
}

func minEatingSpeed(piles []int, h int) int {
	maxPile := max(piles)
	return binarySearch(1, maxPile, piles, h)

}
