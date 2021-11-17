# Cài đặt và ứng dụng hàng đợi
Trong phần này sẽ có 2 problem về Minh Minh và nhiệm vụ của ta liên quan đến các bước thực hiện công việc của cô ấy!
# 1. Minh Minh và N thao tác:
Minh Minh có một hàng đợi **Q** và cô ấy muốn thực hiện **N** thao tác, mỗi thao tác là một trong 2 dạng sau:
- **E x**: thêm x vào hàng đợi và in ra số lượng phần tử của hàng đợi
- **D**: xóa phần tử đầu hàng, đồng thời in phần tử đã xóa và số lượng phần tử của hàng đợi sau khi xóa, 2 giá trị này cách nhau khoảng trắng. Nếu hàng đợi rỗng, in -1 ở chỗ phần tử đã xóa.

Hãy giúp Minh Minh thực hiện các thao tác trên.
## Đầu vào
- Dòng đầu tiên: số nguyên **N** là số thao tác (1 <= N <= 100)
- **N** dòng tiếp theo, mỗi dòng là một thao tác theo cú pháp ở trên (1 <= x <= 100)
## Đầu ra
Mỗi thao tác thêm vào hàng đợi, in ra số lượng phần tử của hàng đợi sau khi thêm; mỗi thao tác xóa, hiển thị 2 số nguyên: phần tử đã xóa (-1 nếu hàng đợi rỗng) và số lượng phần tử của hàng đợi sau khi xóa.
## Sample Input
```
5
E 2
D
D
E 3
D
```
## Sample Output
```
1
2 0
-1 0
1
3 0
```
## Solution
Xem trong [MinhMinh1.c](MinhMinh1.c)
# 2. Minh Minh và n công việc
Có **n** công việc cần thực hiện, các công việc được đánh số từ 1 đến **n**; Minh Minh được đưa 2 danh sách:
- Danh sách 1 gồm thứ tự các công việc được giao cho Minh Minh
- Danh sách 2 là thứ tự tối ưu các công việc Minh Minh phải thực hiện.

Để thực hiện Minh Minh lấy từng công việc được giao cho mình, nếu công việc được lấy ra trùng với thứ tự tối ưu thì thực hiện công việc đó, nếu không trùng với thứ tự tối ưu thì chuyển công việc đó vào cuối danh sách thứ tự các công việc được giao. Quá trình lặp lại đến khi tất cả các công việc được thực hiện. **Mỗi lần chuyển công việc về cuối hay thực thi mất 1 đơn vị thời gian**.

Tính số đơn vị thời gian cần thiết của Minh Minh để hoàn thành n công việc được giao.
## Đầu vào
- Dòng đầu tiên: số nguyên dương n (1 <= n <= 100)
- Dòng thứ 2: danh sách thứ tự công việc được giao
- Dòng thứ 3: danh sách thứ tự tối ưu các công việc cần thực hiện

## Đầu ra
- Một số nguyên duy nhất là số đơn vị thời gian cần thiết để hoàn thành n công việc được giao 

## Ví dụ & Gợi ý
Có 3 công việc, danh sách 1 là 3 2 1; danh sách 2 là 1 3 2. Các bước thực hiện như sau:

- Bước 1: Lấy công việc đầu tiên trong danh sách 1, đó là công việc #3. Vì trường hợp tối ưu là công việc #1 được thực hiện đầu tiên, do đó công việc #3 được đưa trở lại cuối danh sách 1. Thời gian dành cho bước 1: 1
- Bước 2: Lấy công việc kế tiếp trong danh sách 1, đó là công việc #2. Vì trường hợp tối ưu là công việc #1 phải được thực hiện, do đó công việc #2 được đưa trở lại cuối danh sách 1. Thời gian dành cho bước 2: 1
- Bước 3: Lấy công việc kế tiếp trong danh sách 1, đó là công việc #1. Đó cũng là công việc cần thực hiện trong trường hợp tối ưu, do đó, thực hiện công việc #1 và lấy chúng ra khỏi các danh sách. Thời gian dành cho bước 3: 1
- Bước 4: Lấy công việc kế tiếp trong danh sách 1, đó là công việc #3. Đó cũng là công việc cần thực hiện trong trường hợp tối ưu, do đó, thực hiện công việc #3 và lấy chúng ra khỏi các danh sách. Thời gian dành cho bước 4: 1
- Bước 5: Lấy công việc kế tiếp trong danh sách 1, đó là công việc #2. Đó cũng là công việc cần thực hiện trong trường hợp tối ưu, do đó, thực hiện công việc #2 và lấy chúng ra khỏi các danh sách. Thời gian dành cho bước 5: 1
Tổng thời gian thực hiện: **5**
 ## Test case
 - Sample input
```
3
3 2 1
1 3 2
```
- Sample Output
```
5
```
## Solution
Xem trong [MinhMinh2.c](MinhMinh2.c)