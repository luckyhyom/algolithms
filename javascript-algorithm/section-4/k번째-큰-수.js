let input = [13, 15, 34, 23, 45, 65, 33, 11, 26, 42,];
function k(nums, k) {
    let set = new Set();
    for (let i = 0; i < nums.length-2; i++) {
        for (let j = i+1; j < nums.length-1; j++) {
            for (let k = j+1; k < nums.length; k++) {
                set.add(nums[i]+nums[j]+nums[k]);
            }
        }
    }
    
    return Array.from(set).sort((a,b) => b-a)[k-1];
}

console.log(k(input,3));