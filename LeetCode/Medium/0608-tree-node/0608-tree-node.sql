select a.id, if(a.p_id is null, 'Root', if(b.id is null, 'Leaf', 'Inner')) as type
from Tree a
left join Tree b
on a.id = b.p_id
group by a.id
;