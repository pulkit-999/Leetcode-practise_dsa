# Write your MySQL query statement below
SELECT s1.score,(select count(DISTINCT score) from Scores s2 WHERE s1.score<=s2.score) AS 'rank'
from Scores s1
ORDER BY s1.score DESC