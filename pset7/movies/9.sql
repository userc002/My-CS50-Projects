select name from people join stars.person_id = people.id join movies on stars.movie_id = movies.id where movies.year = 2004 order by people.birth;