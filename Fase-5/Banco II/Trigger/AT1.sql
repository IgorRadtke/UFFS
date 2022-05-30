CREATE TABLE if not exists scoreMedio_director(director_id int, name varchar(250), scoreMedio int);


DROP TRIGGER atualiza_score on contents;
DROP FUNCTION atualiza_score();


CREATE OR REPLACE FUNCTION atualiza_score() 
RETURNS trigger AS $$
    DECLARE
        idDirector int;
        i record;

    BEGIN
    for i in SELECT d.director_id from directors as d 
      join content_directors as cd on d.director_id = cd.director_id
      join contents as c on c.content_id = cd.content_id 
      where c.content_id = NEW.content_id

        loop
            idDirector = i.director_id;
            UPDATE scoreMedio_director set media = 
                (SELECT avg(imdb_score)from directors as d
                  join content_directors as cd on d.director_id = cd.director_id
                  join contents as c on c.content_id = cd.content_id 
                  where d.director_id = idDirector)
            where director_id = idDirector;
        END loop;
        RETURN NEW;     
    END;
$$ LANGUAGE plpgsql;


CREATE TRIGGER atualiza_score BEFORE INSERT OR UPDATE ON contents
    FOR EACH ROW EXECUTE PROCEDURE atualiza_score();



-- director_id / name / title / ***** Join de director_id -- e -- contents_id *****
/*SELECT d.director_id, d.name, c.title FROM content_directors as cd 
join directors as d on d.director_id = cd.director_id 
join contents as c on c.content_id = cd.content_id;
*/
-- Insere elementos na tabela 'scoreMedio_director'
/*INSERT INTO scoreMedio_director(director_id, name, scoreMedio) 
    SELECT d.director_id, d.name, avg(c.imdb_score) FROM directors as d 
    join content_directors as cd on cd.director_id = d.director_id
    join contents as c on c.content_id = cd.content_id group by d.director_id, d.name;
*/
