
    // Câu 1: Regex /<[^>]+>/ khớp với những chuỗi sau:
    // Đáp án đúng:
    // <an xml tag>
    // </closetag>
    // <with attribute=”77”>



    // Câu 2: Regex /a.[bc]+/ khớp với:
    // abc
    // abbbbbbbb
    // azc
    // abcbcbcbc
    // azccbbbbcbccc
    // => Sai: ac



    // Câu 3: Regex /(very )+(fat )?(tall|ugly) man/ khớp với:
    // very very fat ugly man
    // very very very tall man
    // => Sai: fat tall man, very fat man



    // Câu 4: Regex khớp chuỗi “abc.def.ghi.jkx”
    // Regex:
    // ^.{3}\..{3}\..{3}\..{3}$
    // \.: kí tự
    // .{3}: 11 kí tự bất kì lặp 3 lần



    // Câu 5: Regex khớp các định dạng số điện thoại:
    // (123) 456 7899
    // (123).456.7899
    // (123)-456-7899
    // 123-456-7899
    // 123 456 7899
    // 1234567899
    // Regex:
    // ^(\(\d{3}\)|\d{3})[ .-]?\d{3}[ .-]?\d{4}$



    // Câu 6: Regex cho chuỗi:
    // - chỉ gồm chữ cái, số
    // - có thể có -, _, hoặc khoảng trắng
    // - không 2 dấu ngăn cách liên tiếp
    // - không bắt đầu/kết thúc bằng dấu ngăn cách
    // Regex:
    // ^[a-zA-Z0-9]+([ \-_][a-zA-Z0-9]+)*$
    