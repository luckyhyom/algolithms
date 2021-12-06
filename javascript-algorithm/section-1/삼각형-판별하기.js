// 길이가 서로 다른 세 막대로 삼각형을 만들 수 있는지 판별

function isTriangle(x, y, z) {
    const max = Math.max(x,y,z)
    const total = x + y + z;
    
    return max < total/2
        ? "Yes"
        : "No"
}

function isTriangle2(x, y, z) {
    const max = Math.max(x,y,z)
    const total = x + y + z;
    const rest = max - total;
    
    return rest > max
        ? "Yes"
        : "No"
}