select round(sum(tiv_2016), 2) as tiv_2016
from Insurance i
where 1 = (
    select count(pid) as cnt
    from Insurance i2
    where i.lon = i2.lon and i.lat = i2.lat
) and 1 < (
    select count(pid) as cnt
    from Insurance i2
    where i.tiv_2015 = i2.tiv_2015
)
;