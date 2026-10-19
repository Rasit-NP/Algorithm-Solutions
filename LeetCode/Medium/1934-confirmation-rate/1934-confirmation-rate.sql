select s.user_id, if(req is null, 0, round(confirmed/req, 2)) as confirmation_rate
from Signups s
left join(
    select user_id, count(time_stamp) as req, sum(if(action = 'confirmed', 1, 0)) as confirmed
    from Confirmations
    group by user_id
) c
on s.user_id = c.user_id 
;