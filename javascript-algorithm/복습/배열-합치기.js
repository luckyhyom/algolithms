let input = [1,3,5];
let input2 = [2,3,6,7,9];

function arr(arr, arr2) {
    let l1 = arr.length;
    let l2 = arr2.length;
    let result = [];
    let p1=p2=0;
    while(p1 < l1 && p2 < l2) {
        if (arr[p1] <= arr2[p2]) result.push(arr[p1++])
        else result.push(arr2[p2++]);
    }

    while (p1 < l1) result.push(arr[p1++]);
    while (p2 < l2) result.push(arr2[p2++]);
    return result;
}

console.log(arr(input,input2));