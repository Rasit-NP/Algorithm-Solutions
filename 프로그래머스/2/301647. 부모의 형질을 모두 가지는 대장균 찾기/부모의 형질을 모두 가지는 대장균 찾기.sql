select c.id, c.genotype, p.genotype as parent_genotype
from ecoli_data c
left join ecoli_data p
on c.parent_id = p.id
where p.genotype is not null and (c.genotype-p.genotype) & p.genotype = 0
;