import express from 'express'
import morgan from 'morgan'
import cookieParser from 'cookie-parser'
import authRouter from './routes/auth.routes.ts'
import taskRouter from './routes/task.routes.ts'

const app = express()

app.use(express.json())

app.use(morgan('dev'))

app.use(cookieParser())

app.use('/api', authRouter)
app.use('/panel', taskRouter)

export default app
