SELECT 
    S.student_id,
    S.student_name,
    su.subject_name,
    COUNT(E.subject_name) AS attended_exams
FROM 
    Students AS S 
CROSS JOIN 
    Subjects AS su
LEFT JOIN 
    Examinations AS E 
    ON S.student_id = E.student_id  
    AND su.subject_name = E.subject_name
GROUP BY 
    S.student_id, 
    S.student_name, 
    su.subject_name
ORDER BY 
    S.student_id,
    su.subject_name;
