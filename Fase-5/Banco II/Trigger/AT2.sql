/* imdb=# \d contents
imdb=# alter table contents add column dia varchar();
ALTER TABLE 
imdb=# alter table contents add column user varchar(100);
ALTER TABLE */



DROP TRIGGER atualiza_score on contents;
DROP FUNCTION atualiza_score();


CREATE OR REPLACE FUNCTION atualiza_score() 
RETURNS trigger AS $$
    DECLARE
        dia date;
        usuario varchar (100);
    BEGIN
        select CURRENT_TIMESTAMP INTO dia;
        select CURRENT_USER INTO usuario;

        NEW.day = dia;
        NEW.c_user = usuario;
        RETURN NEW;     
    END;
$$ LANGUAGE plpgsql;


CREATE TRIGGER atualiza_score BEFORE UPDATE ON contents
    FOR EACH ROW EXECUTE PROCEDURE atualiza_score();

--UPDATE contents SET imdb_score = 5 WHERE content_id = 4;
