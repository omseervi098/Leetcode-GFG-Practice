/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    var list=[]
    for(let i=0;i<arr.length;i++){
        if(fn(arr[i],i)) 
            list.push(arr[i]);
    }
    return list;
};