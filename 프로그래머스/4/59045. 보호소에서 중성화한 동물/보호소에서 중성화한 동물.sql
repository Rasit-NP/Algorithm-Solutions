select i.animal_id, i.animal_type, i.name
from animal_ins i
left join animal_outs o
on i.animal_id = o.animal_id
where substr(sex_upon_intake, 1, 6) = 'Intact' && substr(sex_upon_outcome, 1, 6) != 'Intact'
order by i.animal_id
;