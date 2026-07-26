<h2><a href="https://www.geeksforgeeks.org/problems/happy-number1408/1">Digit Square Sequence</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given a positive integer<strong> n</strong>, generate a sequence by repeatedly replacing the current number with the sum of the squares of its digits.</span></p>
<p><span style="font-size: 18px;">Find whether this sequence eventually reaches 1. Return <strong>true</strong> if it does, otherwise return <strong>false</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 19
<strong>Output:</strong> true
<strong>Explanation:</strong>
19 = 1² + 9² = 82
82 = 8² + 2² = 68
68 = 6² + 8² = 100
100 = 1² + 0² + 0² = 1
Since the sequence reaches 1, return true.</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> n = 20
<strong>Output: </strong>false
<strong>Explanation: <br></strong></span><span style="font-size: 18px;">20 = 2² + 0² = 4
4 = 4² = 16
16 = 1² + 6² = 37
37 = 3² + 7² = 58
58 = 5² + 8² = 89
89 = 8² + 9² = 145
145 = 1² + 4² + 5² = 42
42 = 4² + 2² = 20
The sequence enters a cycle without reaching 1, so return false.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n ≤ 10<sup>9</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Mathematical</code>&nbsp;