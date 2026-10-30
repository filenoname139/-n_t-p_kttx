[README.md](https://github.com/user-attachments/files/34191025/README.md)
# -n_t-p_kttx# Tổng hợp Bài tập Thuật toán C++

Tài liệu này giải thích chi tiết về cách vận hành, độ phức tạp thời gian và không gian của các bài toán trong thư mục này.

---

## 1. Bài toán: Đếm Bò (`dem_bo.cpp`)
**Yêu cầu:** Tìm độ dài lớn nhất của một đoạn liên tiếp các con bò có tổng số hiệu chia hết cho 7.

### Cách vận hành:
- **Nguyên lý:** Sử dụng kỹ thuật **Prefix Sum (Tổng tiền tố)** và **Modulo**. Một đoạn từ $i+1$ đến $j$ có tổng chia hết cho 7 nếu $(S_j - S_i) \equiv 0 \pmod 7$, hay $S_j \equiv S_i \pmod 7$.
- **Thực hiện:**
    1. Tính mảng tổng tiền tố `pre` lấy dư cho 7.
    2. Sử dụng mảng `xh_dau` kích thước 7 để lưu vị trí xuất hiện đầu tiên của từng giá trị dư (0-6).
    3. Duyệt qua mảng `pre`, nếu gặp một giá trị dư đã xuất hiện trước đó, tính độ dài đoạn và cập nhật kết quả lớn nhất (`res`).

### Độ phức tạp:
- **Thời gian:** $O(n)$ – Chỉ cần duyệt mảng một lần để tính tổng và một lần để tìm kết quả.
- **Không gian:** $O(n)$ – Lưu trữ mảng `pre` và mảng `a`.

---

## 2. Bài toán: Ổ Khóa (`o_khoa.cpp`)
**Yêu cầu:** Kiểm tra xem có thể xoay các vòng của ổ khóa theo hai chiều (cùng hoặc ngược chiều kim đồng hồ) sao cho tổng góc quay cuối cùng chia hết cho 360 độ hay không.

### Cách vận hành:
- **Nguyên lý:** Sử dụng **Bitmask (Mặt nạ bit)** để duyệt toàn bộ các trường hợp.
- **Thực hiện:**
    1. Với mỗi số nguyên `mask` từ $0$ đến $2^n - 1$, mỗi bit của `mask` đại diện cho một hướng quay (0 là trừ, 1 là cộng).
    2. Tính tổng `res` tương ứng với mỗi `mask`.
    3. Nếu có bất kỳ `res` nào chia hết cho 360, kết luận là "YES". Nếu duyệt hết mà không có, kết luận là "NO".

### Độ phức tạp:
- **Thời gian:** $O(2^n \cdot n)$ – Có $2^n$ trạng thái, mỗi trạng thái mất $O(n)$ để tính tổng. Phù hợp với $n \le 15-20$.
- **Không gian:** $O(n)$ – Chỉ cần lưu trữ danh sách các góc quay.

---

## 3. Bài toán: Vòng Tiền Tố (`vong_tien_to.cpp`)
**Yêu cầu:** Đếm số lượng các hoán vị vòng quanh của một mảng sao cho tất cả các tổng tiền tố đều không âm.

### Cách vận hành:
- **Nguyên lý:** Sử dụng **Sliding Window Minimum (Giá trị nhỏ nhất trên cửa sổ trượt)** với `deque`.
- **Thực hiện:**
    1. Gấp đôi mảng để mô phỏng vòng tròn và tính mảng tổng tiền tố `tron` độ dài $2n$.
    2. Để một hoán vị bắt đầu tại $i$ là "tốt", điều kiện là: $\min(P_j) \ge P_i$ với $j \in [i+1, i+n]$.
    3. Duy trì một `deque` để tìm giá trị nhỏ nhất trong cửa sổ kích thước $n$ khi trượt từ đầu đến cuối mảng.

### Độ phức tạp:
- **Thời gian:** $O(n)$ – Mặc dù có vòng lặp trượt nhưng mỗi phần tử chỉ vào và ra khỏi `deque` tối đa một lần.
- **Không gian:** $O(n)$ – Lưu trữ mảng tổng tiền tố đã gấp đôi và `deque`.

---
*Chúc các bạn học tập tốt!*
