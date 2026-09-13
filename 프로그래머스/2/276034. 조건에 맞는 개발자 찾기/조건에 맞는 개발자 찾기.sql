select id, email, first_name, last_name
from developers d
left join skillcodes s
on (d.skill_code - s.code) & s.code = 0
where s.name = 'Python' or s.name = 'C#'
group by id
order by id
;