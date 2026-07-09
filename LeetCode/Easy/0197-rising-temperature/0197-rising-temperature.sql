select tod.id as "id"
from Weather yest
left join Weather tod
on yest.recordDate+1 = tod.recordDate
where yest.temperature < tod.temperature;