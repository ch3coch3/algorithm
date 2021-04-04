# algorithm

## quicksort

---
quicksort(A,p,r)
---
```cpp=
if p < r then
    q = partition(A,p,r)
    quicksort(A,p,q-1)
    quicksort(A,q+1,r)
```
---
partition(A,p,r)
---
```
x = A[r]
i = p-1
for j = p to r-1 do
    if A[j] < x then
        i = i+1
        exchange A[i] A[j]
exchange A[i+1] A[r]
return i+1
```