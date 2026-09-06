select lb.book_id, title, author, genre, publication_year, current_borrowers
from library_books lb
left join(
    select book_id, count(borrow_date) - count(return_date) as current_borrowers
    from borrowing_records
    group by book_id
) br
on lb.book_id = br.book_id
where current_borrowers = total_copies
order by current_borrowers desc, title
;