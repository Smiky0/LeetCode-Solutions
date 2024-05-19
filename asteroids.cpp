class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> space; // collect asteroidss in it
        for (int i = 0; i < asteroids.size(); i++)
        {
            // if stack is empty just push asteroid in stack
            if (space.empty())
            {
                space.push(asteroids[i]);
                continue;
            }
            // if both asteroid on same direction then push the new asteroid
            else if ((asteroids[i] > 0 && space.top() > 0) || (asteroids[i] < 0 && space.top() < 0))
            {
                space.push(asteroids[i]);
            }
            // if asteroid going away from each other
            else if (asteroids[i] > 0 && space.top() < 0)
            {
                space.push(asteroids[i]);
            }
            // asteroid going towards each other
            else
            {
                // if new asteroid is smaller than space asteriod
                if (abs(asteroids[i]) < abs(space.top()))
                {
                    // smash new asteroid
                    continue;
                }
                // if space asteroid is smaller than new asteroid
                else if (abs(asteroids[i]) > abs(space.top()))
                {
                    // smash space asteroid as many as possible
                    while (!space.empty())
                    {
                        space.pop();
                        // if space asteroid is going in same direction or away from each other
                        if (space.top() < 0)
                        {
                            break;
                        }
                        // if next space asteroid is bigger or equal to new asteroid (asteroid[i])
                        if (abs(asteroids[i]) <= abs(space.top()))
                        {
                            // stop breaking space asteroids
                            break;
                        }
                    }
                    // if space gets empty after destroying asteroids
                    if (space.empty())
                    {
                        // push new asteroid
                        space.push(asteroids[i]);
                        continue;
                    }
                    // if going on same direction
                    if (space.top() < 0)
                    {
                        // push new asteroid
                        space.push(asteroids[i]);
                        continue;
                    }
                    // if space asteroid is same as new asteroid (asteroid[i])
                    if (abs(space.top()) == abs(asteroids[i]))
                    {
                        // smash both asteroid
                        space.pop();
                        continue;
                    }
                    // if space asteroid is bigger than new asteroid
                    if (abs(space.top()) > abs(asteroids[i]))
                    {
                        // smash new asteroid
                        continue;
                    }
                }
                // if both asteriod are of same size
                else
                {
                    // smash both
                    space.pop();
                    continue;
                }
            }
        }
        asteroids.clear();
        while (!space.empty())
        {
            asteroids.push_back(space.top());
            space.pop();
        }
        reverse(asteroids.begin(), asteroids.end());
        return asteroids;
    }
};