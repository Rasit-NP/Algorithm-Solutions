with TotalStat as (
    select count(*) as total from Users
)
select contest_id, round(count(user_id) * 100/total, 2) as percentage
from Register
cross join TotalStat
group by contest_id
order by percentage desc, contest_id
;