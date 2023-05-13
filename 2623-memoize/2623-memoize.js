/**
 * @param {Function} fn
 */
function isEqual(a, b) {
    return Array.isArray(a) &&
        Array.isArray(b) &&
        a.length === b.length &&
        a.every((val, index) => val === b[index]);
}
function memoize(fn) {
    var dict={}
    return function(...args) {
        if(dict[args]!=null) return dict[args];
        else{
            let tmp=fn(...args);
            dict[args]=tmp;
            return tmp;
        }
        
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */