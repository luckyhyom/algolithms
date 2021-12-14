let input = [1,3,9,5,2];
let input2 = [3,2,5,7,8];

function same(arr,arr2) {
    let result = [];
    if(arr.length > arr2.length) {
        result = arr2.filter((v) => {
            return arr.indexOf(v) > -1;
        })
    } else {
        result = arr.filter((v) => {
            return arr2.indexOf(v) > -1;
        })
    }

    return result.sort((a,b) => a-b);
}

function same2(arr,arr2) {
    let result = [];
    // 정렬 기준을 주지 않으면 문자열로 치환 후 비교함.
    arr.sort((a,b) => a-b);
    arr2.sort((a,b) => a-b);
    let p1=p2=0;
    while (p1 < arr.length && p2 < arr2.length) {
        if (arr[p1] > arr2[p2]) {
            p2++;
        }else if (arr[p1] < arr2[p2]) {
            p1++;
        } else if (arr[p1] === arr2[p2]) {
            result.push(arr[p1]);
            p1++;
            p2++;
        }
    }
    return result;
}

console.log(same2(input,input2));