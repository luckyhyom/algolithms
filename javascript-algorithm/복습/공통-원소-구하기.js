let input = [1,3,9,5,2];
let input2 = [3,2,5,7,8];

function solution(arr,arr2) {
    for (let i = 0; i < arr.length-1; i++) {
        let temp = i;
        for (let j = i+1; j < arr.length; j++) {
            if (arr[i] > arr[j]) {
                temp =  arr[i]
                arr[i] = arr[j]
                arr[j] = temp
            }
            if (arr2[i] > arr2[j]) {
                temp =  arr2[i]
                arr2[i] = arr2[j]
                arr2[j] = temp
            }
        }
    }

    let result = [];
    let p1 = 0;
    let p2 = 0;

    while (p1 < arr.length && p2 < arr2.length)  {
        if (arr[p1] === arr2[p2]) {
            result.push(arr[p1++]);
            p2++;
        }
        else if (arr[p1] < arr2[p2]) p1++
        else if (arr[p1] > arr2[p2]) p2++
    }
    
    return result;
}

console.log(solution(input,input2));