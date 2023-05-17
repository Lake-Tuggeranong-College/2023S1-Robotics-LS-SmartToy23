# Programming Logic

> For each behaviour, create the mermaid flowchart. Start each flowchart with a Heading naming the functionality. Delete this comment prior to submission.

## Goodbye Function

```mermaid
flowchart TD
s(Start) --> check(detect movement?)
check --> |false| G(Goodbye)
check --> |true| s
```
## Weather Check Function

```mermaid
flowchart TD
    S(Start)-->Speech[/Input - What is weather?/]
    Speech --> Weather[var temp]
Weather --> Check{temp < 13}
Check -->|true| cold[/output - it's cold/]
Check -->|false| warm[/output - it's warm/]
E(End)
cold --> E
warm --> E
   
```
## Wake Up Function

```mermaid
flowchart TD
S(Start) --> Visual{is movement detected}
Visual -->|yes| green[Task - Turn green Light On ]
Visual -->|no| red[Task - Turn red Light On ]
green --> wave[Task - Turn On fan]


```
