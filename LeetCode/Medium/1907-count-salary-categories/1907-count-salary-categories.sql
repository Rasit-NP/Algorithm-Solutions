select category, count(income) as accounts_count
from (
    select 'Low Salary' as category
    union all select 'Average Salary'
    union all select 'High Salary'
) t
left join Accounts a
on t.category = if(income < 20000, 'Low Salary', if(income > 50000, 'High Salary', 'Average Salary'))
group by category
;