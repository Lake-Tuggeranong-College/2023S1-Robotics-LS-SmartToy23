# Programming Logic

> For each behaviour, create the mermaid flowchart. Start each flowchart with a Heading naming the functionality. Delete this comment prior to submission.

## Goodbye Function

```mermaid
flowchart TD
s(Start) --> check(is crash sensor pressed)
check --> |false| Off(Red light off)
check --> |true| Red(Display red light)
```
## Music Play Function

```mermaid
flowchart TD
    S(Start)-->Sonar[/Input - Distance?/]
    Sonar --> Distance[var distance]
Sonar --> Check{distance < 50}
Check -->|true| play[/output - turn on yellow light and play sound/]
Check -->|false| noplay(Do nothing)
E(End)

   
```
## Wake Up Function

```mermaid
flowchart TD
S(Start) --> Visual{is movement detected line sensor}
Visual -->|yes| green[Task - Turn green Light On]
green --> wave[Task - Turn On fan]
Visual -->|no| red[Task - Turn green light off]



```
