#!/bin/bash

# create SQL files
touch 1.sql 2.sql 3.sql 4.sql 5.sql 6.sql 7.sql 8.sql

# write SQL queries to files
echo "SELECT name FROM songs;" > 1.sql
echo "SELECT name FROM songs ORDER BY tempo ASC;" > 2.sql
echo "SELECT name FROM songs ORDER BY duration DESC LIMIT 5;" > 3.sql
echo "SELECT name FROM songs WHERE danceability > 0.75 AND energy > 0.75 AND valence > 0.75;" > 4.sql
echo "SELECT AVG(energy) FROM songs;" > 5.sql
echo "SELECT name FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name = \"Post Malone\");" > 6.sql
echo "SELECT AVG(energy) FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name = \"Drake\");" > 7.sql
echo "SELECT name FROM songs WHERE name LIKE '%feat.%';" > 8.sql

echo "Done creating SQL files!"

