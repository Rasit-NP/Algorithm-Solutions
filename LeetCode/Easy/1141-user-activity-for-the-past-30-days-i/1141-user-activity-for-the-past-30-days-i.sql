select activity_date as day, count(user_id) as active_users
from (
    select user_id, activity_date
    from Activity
    group by user_id, activity_date
    having activity_date > '2019-06-27' and activity_date <= '2019-07-27'
) t
group by day
;