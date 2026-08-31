select name, if (travelled_distance is null, 0, travelled_distance) as travelled_distance
from Users u
left join (
    select user_id, sum(distance) as travelled_distance
    from Rides
    group by user_id
) r
on u.id = r.user_id
order by travelled_distance desc, name
;