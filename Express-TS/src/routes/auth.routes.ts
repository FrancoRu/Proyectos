import { Router } from 'express'
import {
  login,
  register,
  logout,
  profile
} from '../controllers/auth.controllers.ts'
import { loginSchema, registerSchema } from '../schemas/auth.schema.ts'
import { validateSchema } from '../middlewares/validate.middleware.ts'
import { authRequired } from '../middlewares/validateToken.ts'
const router = Router()

router.post('/register', validateSchema(registerSchema), register)
router.post('/login', validateSchema(loginSchema), login)
router.get('/logout', logout)
router.get('/profile', authRequired, profile)

export default router
