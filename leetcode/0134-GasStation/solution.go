// Space complexity O(N)
// Compute complexity O(N)

func canCompleteCircuit(gas []int, cost []int) int {
    extraGasTillStart := -1
    startIdx := 0
    sumExtraGas := 0

    for idx, g := range gas {
        currExtraGas := g - cost[idx]
        sumExtraGas += currExtraGas
        if extraGasTillStart < 0 {
            startIdx = idx
            extraGasTillStart = currExtraGas
        } else {
            extraGasTillStart += currExtraGas
        }
    }

    if sumExtraGas < 0 {
        return -1
    }

    return startIdx
}